open Express;

module Db = Database.Make(Fs);

/* root directory when called via npm script */
let cwd = Node.Process.cwd();

let printObservation = (obs: Observations_t.observation) => {
  Js.log("new observation:");
  Js.log2("date: %s", Js.Date.toUTCString(obs.date));
  obs;
};

let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://127.0.0.1:3000"
  };

let app = express();
App.use(app, Middleware.json());

App.useOnPath(
  app,
  ~path="/",
  {
    let options = Static.defaultOptions();
    Static.make(cwd ++ "/public", options) |> Static.asMiddleware;
  },
);

App.get(app, ~path="/observations") @@
Middleware.from((_next, _req, res) =>
  res
  |> Response.status(Response.StatusCode.Ok)
  |> Response.sendJson(
       Atdgen_codec_runtime.Encode.encode(
         Observations_bs.write_observations,
         Db.readObservations(),
       ),
     )
);

let raiseIfNone =
  fun
  | Some(value) => value
  | None => failwith("Body is none");

App.post(app, ~path="/observation") @@
Middleware.from((_next, req) =>
  req
  |> Request.bodyJSON
  |> raiseIfNone
  |> Atdgen_codec_runtime.Decode.decode(Observations_bs.read_observation)
  |> printObservation
  |> Db.saveObservation
  |> (() => Response.sendStatus(Response.StatusCode.Ok))
);

let server = App.listen(app, ~port=3000, ~onListen, ());
