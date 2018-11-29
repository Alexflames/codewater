// Learn more about F# at http://fsharp.org
// See the 'F# Tutorial' project for more help.

[<EntryPoint>]
let main argv = 
    printfn "%A" argv

	let nplus1 num = num + 1
	let div2 (f : float -> float, num : float) = (f num) / 2.0

    0 // return an integer exit code
