module type Connection = {
  let readObservations: unit => Observations_t.observations;
  let saveObservation: Observations_t.observation => unit;
};

module Make = (Connection: Connection) => {
  include Connection;
};
