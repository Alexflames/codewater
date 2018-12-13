// Task 1-1
//let (^!) (a:int) = a * a
//for i in 5 .. 17 do
//    printf "%i \n" ((^!) i - 1)

// Task 1-2
let cancel = 12 // System.Console.ReadLine() |> int
let mutable i = 0
while i < 27 && i <> cancel do
    i <- i + 1
    printf "%i " i

// Task 1-3
open System
let (^!) (a:double) = a * a
let F x y = 
    let delim = Math.Sqrt(Math.Pow(Math.E, (^!) x + (^!) y)) - y * x
    let denom = (^!) x + (^!) y 
    let ln = Math.Log(Math.Sqrt((^!) ((^!) x)) / Math.Sqrt((^!) ((^!) y)))
    1.0 / 2.0 * delim / denom + ln

printf "%f \n" (F 2.0 3.0)

// Task 1-4
let F2 x =
    let x1 = x / 100
    let x3 = x % 10
    let x2 = x / 10 % 10
    printf "Сумма: %i \n" (x1 + x2 + x3) 
    printf "Произведение: %i \n" (x1 * x2 * x3)
    printf "Y: %i%i%i\n" x3 x2 x1

F2 281

// Task 2-1
open System
type VolumeFigure =
    new () = {}
    abstract member volume : unit -> float
    default this.volume() = failwith "not implemented"

    abstract member surface : unit -> float
    default this.surface() = failwith "not implemented"

type Sphere(r) =
    inherit VolumeFigure()
    override this.volume() = 4. / 3. * Math.PI * r * r * r
    override this.surface() = 4. * Math.PI * r * r

type HollowSphere(rOut, rIns) =
    inherit Sphere(rOut)
    override this.volume() = 4. / 3. * Math.PI * rOut * rOut * rOut - 4. / 3. * Math.PI * rIns * rIns * rIns

let lst = [new Sphere(3.) :> VolumeFigure; new HollowSphere(5., 3.) :> VolumeFigure]
let mutable num = 0

for i in lst do
    printf "Объем фигуры %i: %f. Площадь поверхности: %f \n" num (i.volume()) (i.surface())
    num <- num + 1

printf "%f" ((new VolumeFigure()).volume())

let conjuction x y = x && y
let disjunction x y = x || y
let not x = not x
let equal x y = (x = y)
let following x y = disjunction (not x) y
let exclusive x y = disjunction (conjuction x (not y)) (conjuction y (not x))

let task3 x y z = conjuction x (disjunction y (not z))

let printTruthTable f =
    printfn "Z: true"
    printfn "X \ Y | true  | false |"
    printfn "      +-------+-------+"
    printfn " true | %5b | %5b |" (f true true true) (f true false true)
    printfn "false | %5b | %5b |" (f false true true) (f false false true)
    printfn "      +-------+-------+"
    printfn "Z: false"
    printfn "X \ Y | true  | false |"
    printfn "      +-------+-------+"
    printfn " true | %5b | %5b |" (f true true false) (f true false false)
    printfn "false | %5b | %5b |" (f false true false) (f false false false)
    printfn "      +-------+-------+"

printTruthTable task3