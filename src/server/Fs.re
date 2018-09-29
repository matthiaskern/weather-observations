let data_file = "observations.json";

let readObservations = () =>
  Node_fs.readFileAsUtf8Sync(data_file)
  |> Js.Json.parseExn
  |> Atdgen_codec_runtime.Decode.decode(Observations_bs.read_observations);

let saveObservations = observations =>
  observations
  |> Atdgen_codec_runtime.Encode.encode(Observations_bs.write_observations)
  |> Js.Json.stringifyWithSpace(_, 2)
  |> Node_fs.writeFileAsUtf8Sync(data_file);

let saveObservation = observation =>
  saveObservations(readObservations() @ [observation]);
