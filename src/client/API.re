type error('err) =
  | NetworkError
  | ExpectedJson;

let getObservations = () =>
  Js.Promise.(
    Fetch.fetch("/observations")
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json
         |> Atdgen_codec_runtime.Decode.decode(
              Observations_bs.read_observations,
            )
         |> resolve
       )
  );

let postObservation = obs => {
  open Fetch;
  let options =
    RequestInit.make(
      ~method_=Post,
      ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json"}),
      ~body=
        BodyInit.make(
          Atdgen_codec_runtime.Encode.encode(
            Observations_bs.write_observation,
            obs,
          )
          |> Js.Json.stringify,
        ),
      (),
    );

  Js.Promise.(
    fetchWithInit("/observation", options)
  );
};
