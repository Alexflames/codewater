// Задание 13-1
// Тонна-грамм
[<Measure>]
type gr
[<Measure>]
type ton

let gr2ton (d:int<gr>) = d / 1000000<gr/ton> 
let ton2gr (d:int<ton>) = d * 1000000<gr/ton>

let metalSlice : int<ton> = 25<ton>
let appleSack : int<gr> = 25000000<gr>

let are_eq = 
    if ((ton2gr metalSlice) = appleSack && (gr2ton appleSack) = metalSlice)
    then printfn "Одинаковый вес"

// Задание 13-2
open System
let S_P a b c = 
    let PP = (a + b + c) / 2. 
    (Math.Sqrt(PP * (PP - a) * (PP - b) * (PP - c)), PP * 2.)

S_P 2. 3. 5.

// Задание 13-3
type Worker = {
    surname : string
    name : string
    exp : int
}

open System.Collections

let workers = 
    [   {surname = "Ivanov"; name = "Ivan"; exp = 1}; 
        {surname = "Grigoriev"; name = "Aleksey"; exp = 3};
        {surname = "Delta"; name = "Lamblador"; exp = 10}]
let f3 works = works |> List.iter(fun w -> printfn "%s %s %i" w.surname w.name w.exp)
f3 workers

// Задание 13-5