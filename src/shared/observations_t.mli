(* Auto-generated from "observations.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type coordinates = (float * float)

type location = { name: string; coordinates: coordinates }

type date = Js.Date.t

type observation = {
  id: string;
  date: date;
  temperature: float;
  location: location
}

type observations = observation list
