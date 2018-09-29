/* generate some entries in the db */
let observations: Observations_t.observations = [
  {
    id: NanoId.make(),
    date: Js.Date.make(),
    temperature: 20.,
    location: {
      name: "Tokio",
      coordinates: (35.6584421, 139.7328635),
    },
  },
  {
    id: NanoId.make(),
    date: Js.Date.make(),
    temperature: 4.,
    location: {
      name: "Helsinki",
      coordinates: (60.1697530, 24.9490830),
    },
  },
  {
    id: NanoId.make(),
    date: Js.Date.make(),
    temperature: 10.,
    location: {
      name: "New York",
      coordinates: (40.7406905, (-73.9938438)),
    },
  },
  {
    id: NanoId.make(),
    date: Js.Date.make(),
    temperature: 12.,
    location: {
      name: "Amsterdam",
      coordinates: (52.3650691, 4.9040238),
    },
  },
  {
    id: NanoId.make(),
    date: Js.Date.make(),
    temperature: 35.,
    location: {
      name: "Dubai",
      coordinates: (25.092535, 55.1562243),
    },
  },
];

List.iter(Fs.saveObservation, observations);
