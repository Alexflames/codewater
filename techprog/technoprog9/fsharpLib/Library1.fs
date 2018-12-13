namespace fsharpLib

type IRepairable = 
    abstract wear : float
    abstract repairCost : unit -> int
    abstract repair : float -> unit

type Building(address : string, square : int, floors : int, dateC : string, wear : float) =
    let mutable address = address
    let mutable square = square
    let mutable floors = floors
    let mutable dateC = dateC
    member public this.getData = (address, square, floors, dateC)
    member public this.print() = 
        printfn "Адрес: %s \n Площадь: %i \n  Кол-во этажей: %i \n Дата постройки %s" 
            address square floors dateC


    interface IRepairable with
        override this.wear = wear
        override this.repairCost() = 
            int (wear * (float square))
        override this.repair(new_wear) =
            printfn "Сдание отремонтировано"

