[@bs.module] external generate: (string, int) => string = "nanoid/generate";

let make = () =>
  generate(
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",
    22,
  );
