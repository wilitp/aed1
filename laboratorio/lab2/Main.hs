-- Ejercicio 1 y 2

data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Ord, Eq)

titulo Computacion = "Licenciatura en Ciencias de la Computacion"
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Astronomia = "Licenciatura en Astronomia"

-- Ejercicio 3

-- a  
type Ingreso = Int

data Cargo = Titular | Asociado | Adjunto | Asistente | Auxiliar
data Area = Administrativa | Ensenanza | Economica | Postgrado

data Persona = Decano
            | Docente Cargo
            | NoDocente Area
            | Estudiante Carrera Ingreso

-- b 
-- El tipo del constructor docente es Cargo -> Persona

-- c

esCargo :: Cargo -> Persona -> Bool 
esCargo Titular (Docente Titular) = True
esCargo Asociado (Docente Asociado) = True
esCargo Adjunto (Docente Adjunto) = True
esCargo Asistente (Docente Asistente) = True
esCargo _ _ = False

cuantosDoc :: [Persona] -> Cargo -> Int

cuantosDoc ((Docente c):xs) y | esCargo y (Docente c) = 1 + cuantos_doc xs y 
                              | otherwise = cuantos_doc xs y

cuantosDoc (x:xs) y = cuantos_doc xs y
cuantosDoc [] _ = 0
cuantos_doc = cuantosDoc

-- d

cuantosDoc' :: [Persona] -> Cargo -> Int
cuantosDoc' xs y = length (filter (esCargo y) xs)


cuantos_doc' = cuantosDoc'

-- Ejercicio 4

-- a

primerElemento :: [a] -> Maybe a

primerElemento [] = Nothing
primerElemento (x:xs) = Just x

-- Ejercicio 5

data Cola = VaciaC | Encolada Persona Cola

atender :: Cola -> Maybe Cola

atender VaciaC = Nothing
atender (Encolada p c) = Just c

encolar :: Persona -> Cola -> Cola

encolar = Encolada

busca :: Cola -> Cargo -> Maybe Persona

busca VaciaC _ = Nothing

busca (Encolada (Docente s) c) y | esCargo y (Docente s) = Just (Docente s)
                       | otherwise = busca c y

-- Ejercicio 6 TODO

data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b )
type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String

