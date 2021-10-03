-- Ejercicio 1 y 2

data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Ord, Eq, Show)

titulo Computacion = "Licenciatura en Ciencias de la Computacion"
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Astronomia = "Licenciatura en Astronomia"

-- Ejercicio 3

-- a  
type Ingreso = Int

data Cargo = Titular | Asociado | Adjunto | Asistente | Auxiliar deriving Show
data Area = Administrativa | Ensenanza | Economica | Postgrado deriving Show

data Persona = Decano
            | Docente Cargo
            | NoDocente Area
            | Estudiante Carrera Ingreso deriving Show

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

data Cola = VaciaC | Encolada Persona Cola deriving Show

-- a
atender :: Cola -> Maybe Cola

atender VaciaC = Nothing
atender (Encolada p c) = Just c

-- b
encolar :: Persona -> Cola -> Cola

encolar p VaciaC = Encolada p VaciaC

encolar p (Encolada a c) = Encolada a (encolar p c)

busca :: Cola -> Cargo -> Maybe Persona

busca VaciaC _ = Nothing

busca (Encolada p c) y | esCargo y p = Just p
                       | otherwise = busca c y

colaPrueba = Encolada Decano (Encolada (Docente Adjunto) (Encolada Decano VaciaC))
colaPrueba1 = Encolada Decano (Encolada (Docente Asociado) VaciaC)

-- Ejercicio 6 TODO

data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b ) deriving Show
type GuiaTelefonica = ListaAsoc String Int

-- a
laLong :: ListaAsoc a b -> Int

laLong Vacia = 0

laLong (Nodo x y la) = 1 + laLong la

la_long = laLong

-- b
laConcat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b

laConcat Vacia y = y
laConcat (Nodo a b l) y = Nodo a b (laConcat l y)
la_concat = laConcat

-- c

laPares :: ListaAsoc a b -> [(a, b)]

laPares Vacia = []

laPares (Nodo a b l) = (a,b) : laPares l

la_pares = laPares

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b 

laBusca Vacia _ = Nothing

laBusca (Nodo a b l) x = if a==x then Just b else laBusca l x

la_busca = laBusca

la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b 

laBorrar _ Vacia = Vacia

laBorrar x (Nodo a b l) | a==x = laBorrar x l 
                        | otherwise = Nodo a b (laBorrar x l)

la_borrar = laBorrar

testLa = Nodo 1 2 (Nodo 3 4 (Nodo 5 6 Vacia))

-- Ejercicio 7

data Arbol a = Hoja | Rama (Arbol a) a (Arbol a)

-- Arbol de prueba
tree = Rama Hoja 3 (Rama (Rama Hoja 5 Hoja) 4 Hoja)

-- a

aLong :: Arbol a -> Int

aLong Hoja = 0

aLong (Rama t1 v t2) = 1 + aLong t1 + aLong t2

a_long = aLong

-- b
a_hojas :: Arbol a -> Int

aHojas Hoja = 1

aHojas (Rama t1 v t2) = aHojas t1 + aHojas t2

a_hojas = aHojas

-- c
a_inc :: Num a => Arbol a -> Arbol a

aInc Hoja = Hoja

aInc (Rama t1 v t2) = Rama (aInc t1) (v+1) (aInc t2)

a_inc = aInc

-- d
a_map :: (a -> b) -> Arbol a -> Arbol b

-- aMap _ Hoja = Hoja

aMap f (Rama t1 v t2) = Rama (aMap f t1) (f v) (aMap f t2)

a_map = aMap

