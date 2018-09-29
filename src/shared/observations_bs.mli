(* Auto-generated from "observations.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type coordinates = Observations_t.coordinates

type location = Observations_t.location = {
  name: string;
  coordinates: coordinates
}

type date = Observations_t.date

type observation = Observations_t.observation = {
  id: string;
  date: date;
  temperature: float;
  location: location
}

type observations = Observations_t.observations

val read_coordinates :  coordinates Atdgen_codec_runtime.Decode.t

val write_coordinates :  coordinates Atdgen_codec_runtime.Encode.t

val read_location :  location Atdgen_codec_runtime.Decode.t

val write_location :  location Atdgen_codec_runtime.Encode.t

val read_date :  date Atdgen_codec_runtime.Decode.t

val write_date :  date Atdgen_codec_runtime.Encode.t

val read_observation :  observation Atdgen_codec_runtime.Decode.t

val write_observation :  observation Atdgen_codec_runtime.Encode.t

val read_observations :  observations Atdgen_codec_runtime.Decode.t

val write_observations :  observations Atdgen_codec_runtime.Encode.t

