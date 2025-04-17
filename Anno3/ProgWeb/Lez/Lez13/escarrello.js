"use strict";

let products = [
    {name: "Product 1", price : 10},
    {name : "Product 2", price : 20},
    {name : "Product 3", price : 30},
];

let cart =
{
    items: [],
    total: 0,
    addItem: function(product)
    {
        this.items.push(product);
        this.total += product.price;
    }
};