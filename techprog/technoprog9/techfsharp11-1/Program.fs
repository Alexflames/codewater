open System

// Learn more about F# at http://fsharp.org
// See the 'F# Tutorial' project for more help.

[<EntryPoint>]
let main argv = 
    printfn "%A" argv
    let a = -1.25
    let b = -1.5
    let c = 0.75
    let x0 = -1.5
    let xk = 3.5
    let dx = 0.5
    let y x = 0.01 * b * c / x + Math.Cos (a * a * a * x)
    let rec tabfun x = 
        let pr = printf "x = %A  y = %A \n" x (y x)
        if x < xk then tabfun (x + dx)
    tabfun x0
    0 // return an integer exit code
