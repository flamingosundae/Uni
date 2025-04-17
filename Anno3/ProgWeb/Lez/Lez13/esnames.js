let names = ["tizio", "caio", "semprionio"];

names = names.map((item) => "Dr." + item.toUpperCase());
names.reduce((acc, item, idx, arr) => item.length> arr[acc].length ? idx : acc, 0);