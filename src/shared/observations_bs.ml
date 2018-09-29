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

let write_coordinates = (
  Atdgen_codec_runtime.Encode.tuple2
    (
      Atdgen_codec_runtime.Encode.float
    )
    (
      Atdgen_codec_runtime.Encode.float
    )
)
let read_coordinates = (
  Atdgen_codec_runtime.Decode.tuple2
    (
      Atdgen_codec_runtime.Decode.float
    )
    (
      Atdgen_codec_runtime.Decode.float
    )
)
let write_location = (
  Atdgen_codec_runtime.Encode.make (fun (t : location) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"name"
          t.name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_coordinates
            )
          ~name:"coordinates"
          t.coordinates
      ]
    )
  )
)
let read_location = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "name"
            ) json;
          coordinates =
            Atdgen_codec_runtime.Decode.decode
            (
              read_coordinates
              |> Atdgen_codec_runtime.Decode.field "coordinates"
            ) json;
      } : location)
    )
  )
)
let write__1 = (
    Atdgen_codec_runtime.Encode.float
  |> Atdgen_codec_runtime.Encode.contramap (Js.Date.valueOf)
)
let read__1 = (
  (
    Atdgen_codec_runtime.Decode.float
  ) |> (Atdgen_codec_runtime.Decode.map (Js.Date.fromFloat))
)
let write_date = (
  write__1
)
let read_date = (
  read__1
)
let write_observation = (
  Atdgen_codec_runtime.Encode.make (fun (t : observation) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"id"
          t.id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_date
            )
          ~name:"date"
          t.date
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.float
            )
          ~name:"temperature"
          t.temperature
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_location
            )
          ~name:"location"
          t.location
      ]
    )
  )
)
let read_observation = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "id"
            ) json;
          date =
            Atdgen_codec_runtime.Decode.decode
            (
              read_date
              |> Atdgen_codec_runtime.Decode.field "date"
            ) json;
          temperature =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.float
              |> Atdgen_codec_runtime.Decode.field "temperature"
            ) json;
          location =
            Atdgen_codec_runtime.Decode.decode
            (
              read_location
              |> Atdgen_codec_runtime.Decode.field "location"
            ) json;
      } : observation)
    )
  )
)
let write__2 = (
  Atdgen_codec_runtime.Encode.list (
    write_observation
  )
)
let read__2 = (
  Atdgen_codec_runtime.Decode.list (
    read_observation
  )
)
let write_observations = (
  write__2
)
let read_observations = (
  read__2
)
