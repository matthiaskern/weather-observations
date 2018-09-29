let str = ReasonReact.string;

let arrayFindExn = (arr, f) => {
  let length = Array.length(arr);
  let rec loop = i =>
    if (i < length) {
      let element = arr[i];
      if (f(element)) {
        arr[i];
      } else {
        loop(i + 1);
      };
    } else {
      failwith("No such array item");
    };
  loop(0);
};

let valueFromEvent = event: string => event->ReactEvent.Form.target##value;
