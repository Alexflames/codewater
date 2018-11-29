let nplus1 num = num + 1.
let div2 (f : float -> float) num = (f num) / 2.0
printfn "%f" (div2 nplus1 7.)

open System
let nplus2 n = n + 2.
let vcylinder r h = Math.PI * r * r * h |> nplus2
printfn "%f" (vcylinder 3. 4.)

let rec numsFromCurToN cur n = 
    let LUL = printf "%A" cur
    if (cur <> n) then numsFromCurToN (cur + 1) n;
let numsFromOneToN n = numsFromCurToN 0 n

numsFromOneToN 10

open System;
type Potion = class
    val public _name : string
    val mutable private _water : int
    val mutable private _red : int
    val mutable private _green : int
    val mutable private _blue : int

    new(name : string, water : int, red : int, green: int, blue : int) = 
     {_name = name; _water = water; _red = red; _green = green; _blue = blue }
    new() = {_name = "unnamed"; _water = 200; _red = 0; _green = 0; _blue = 0 }

    member this.essence = (this._red, this._green, this._blue);
    member this.name = this._name;
    member this.water = this._water;
    member this.fill (water : int, red : int, green : int, blue : int) =
        this._water <- this._water + water;
        this._red <- this._red + red;
        this._green <- this._green + green;
        this._blue <- this._blue + blue;
    member this.print = 
        let (r, g, b) = this.essence;
        printf "Красной жижи: %A Зелёной жижи: %A Синей жижи: %A \n" r g b
end

let pot1 = new Potion("Зелье превращения в картофеля", 500, 244, 122, 66);
pot1.print;
pot1.fill(0, 0, 0, 150); 
pot1.print;