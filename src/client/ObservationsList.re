open Utils;
let component = ReasonReact.statelessComponent(__MODULE__);

let make = (~observations: Observations_t.observations, _children) => {
  ...component,
  render: _self =>
    <>
      <h2> "All observations"->str </h2>
      <ul>
        observations
        ->(
            Belt.List.map(obs =>
              <li key=(obs.id)>
                obs.temperature->Js.Float.toFixed->str
                "C -- "->str
                obs.location.name->str
                " -- "->str
                <date> obs.date->Js.Date.toDateString->str </date>
              </li>
            )
          )
        ->Array.of_list
        ->ReasonReact.array
      </ul>
    </>,
};
