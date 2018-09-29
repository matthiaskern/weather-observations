open Utils;

type state = {
  observations: Observations_t.observations,
  observationStatus: SharedTypes.observationStatus,
};

type action =
  | SetObservations(Observations_t.observations)
  | AddObservation(Observations_t.observation)
  | UpdateObservationStatus(SharedTypes.observationStatus);

let component = ReasonReact.reducerComponent(__MODULE__);

let make = _children => {
  ...component,
  didMount: self =>
    API.getObservations()
    |> Js.Promise.then_(observations =>
         self.send(SetObservations(observations |> Belt.List.reverse))
         |> Js.Promise.resolve
       )
    |> ignore,
  initialState: () => {observations: [], observationStatus: NotSubmitted},
  reducer: (action, state) =>
    switch (action) {
    | SetObservations(observations) =>
      ReasonReact.Update({...state, observations})
    | UpdateObservationStatus(observationStatus) =>
      ReasonReact.Update({...state, observationStatus})
    | AddObservation(observation) =>
      ReasonReact.UpdateWithSideEffects(
        {...state, observationStatus: Submitting},
        (
          self =>
            Js.Promise.(
              API.postObservation(observation)
              |> then_(_ => {
                   self.send(UpdateObservationStatus(Submitted));
                   self.send(
                     SetObservations([
                       observation,
                       ...self.state.observations,
                     ]),
                   );
                   Js.Global.setTimeout(
                     () => self.send(UpdateObservationStatus(NotSubmitted)),
                     500,
                   )
                   ->ignore;
                   resolve();
                 })
              |> catch(_e => {
                   self.send(
                     UpdateObservationStatus(Error("Submitting failed")),
                   );
                   resolve();
                 })
            )
            |> ignore
        ),
      )
    },
  render: ({state: {observations, observationStatus}, send}) =>
    <main>
      <h1> "Weather Observations"->str </h1>
      <ObservationAdder
        handleSubmit={observation => send(AddObservation(observation))}
        observationStatus
      />
      <ObservationsList observations />
    </main>,
};
