open System

[<Measure>]
type gr
[<Measure>]
type ton

let gr2ton (d:float<gr>) = d / 1000000. 
let ton2gr (d:float<ton>) = d * 1000000.

let metalSlice : int<ton> = 25<ton>