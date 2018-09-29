open Utils;

let locations: array(Observations_t.location) = [|
  {name: "Tokio", coordinates: (35.6584421, 139.7328635)},
  {name: "Helsinki", coordinates: (60.1697530, 24.9490830)},
  {name: "New York", coordinates: (40.7406905, (-73.9938438))},
  {name: "Amsterdam", coordinates: (52.3650691, 4.9040238)},
  {name: "Dubai", coordinates: (25.092535, 55.1562243)},
|];

type action =
  | UpdateTemperature(float)
  | UpdateLocation(Observations_t.location);

type state = {
  temperature: float,
  location: Observations_t.location,
};

let component = ReasonReact.reducerComponent(__MODULE__);

let make =
    (
      ~observationStatus: SharedTypes.observationStatus,
      ~handleSubmit: Observations_t.observation => unit,
      _children,
    ) => {
  ...component,
  initialState: () => {temperature: 0., location: locations[0]},
  reducer: (action, state) =>
    switch (action) {
    | UpdateTemperature(temperature) =>
      ReasonReact.Update({...state, temperature})
    | UpdateLocation(location) => ReasonReact.Update({...state, location})
    },
  render: ({state, send}) =>
    switch (observationStatus) {
    | NotSubmitted
    | Submitting =>
      <div>
        <input
          value=state.temperature->Js.Float.toString
          type_="number"
          placeholder="Temperature"
          required=true
          onChange=(
            evt =>
              send(
                UpdateTemperature(Js.Float.fromString(valueFromEvent(evt))),
              )
          )
        />
        <select
          required=true
          value={state.location.name}
          onChange=(
            evt => {
              let value = valueFromEvent(evt);

              send(
                UpdateLocation(
                  Utils.arrayFindExn(locations, loc => loc.name == value),
                ),
              );
            }
          )>
          locations
          ->(Belt.Array.map(loc => <option> loc.name->str </option>))
          ->ReasonReact.array
        </select>
        <button
          onClick=(
            _ =>
              handleSubmit({
                id: NanoId.make(),
                date: Js.Date.make(),
                location: state.location,
                temperature: state.temperature,
              })
          )>
          "Submit"->str
        </button>
        (observationStatus == Submitting ? "Submitting..." : "")->str
      </div>
    | Submitted => "Your submission has been recorded"->str
    | Error(e) =>
      <div>
        <input
          value=state.temperature->Js.Float.toString
          type_="number"
          placeholder="Temperature"
          required=true
          onChange=(
            evt =>
              send(
                UpdateTemperature(Js.Float.fromString(valueFromEvent(evt))),
              )
          )
        />
        <select
          required=true
          value={state.location.name}
          onChange=(
            evt => {
              let value = valueFromEvent(evt);

              send(
                UpdateLocation(
                  Utils.arrayFindExn(locations, loc => loc.name == value),
                ),
              );
            }
          )>
          locations
          ->(Belt.Array.map(loc => <option> loc.name->str </option>))
          ->ReasonReact.array
        </select>
        <button
          onClick=(
            _ =>
              handleSubmit({
                id: NanoId.make(),
                date: Js.Date.make(),
                location: state.location,
                temperature: state.temperature,
              })
          )>
          "Submit"->str
        </button>
        e->str
      </div>
    },
};
