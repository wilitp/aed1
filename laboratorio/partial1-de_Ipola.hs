-- ---- Ejercicio 1 -----------------

-- -- Tipos Ejercicio 1
-- data EmpresaTelefono = Claro | Personal | Movistar | Tuenti deriving Show
-- type Frase = String

-- -- (“Claro, La red mas poderosa”, “Personal, es como
-- -- vos”, “Movistar, Compartida la vida es mas... ”, “Tuenti es la mas economica”).

-- fraseEmpresa :: EmpresaTelefono -> Frase

-- fraseEmpresa Movistar = "Compartida la vida es mas"
-- fraseEmpresa Claro = "La red mas poderosa"
-- fraseEmpresa Tuenti = "Tuenti es la mas economica"
-- fraseEmpresa Personal = "Es como vos"

-- fraseDeClaro = fraseDeClaro -- "La red mas poderosa"

-- ---- Ejercicio 2 -----------------

-- -- Tipos Ejercicio 2
-- -- type NombrePersona = String
-- -- data MisEmpresas = Ninguna | AgregaEmpresa EmpresaTelefono NombrePersona MisEmpresas deriving Show

-- tengoEmpresa :: MisEmpresas -> EmpresaTelefono -> NombrePersona -> Bool

-- -- Caso base

-- tengoEmpresa Ninguna e p = False

-- tengoEmpresa (AgregaEmpresa Claro nom tl) Claro p = p == nom || tengoEmpresa tl Claro p
-- tengoEmpresa (AgregaEmpresa Personal nom tl) Personal p = p == nom || tengoEmpresa tl Personal p
-- tengoEmpresa (AgregaEmpresa Movistar nom tl) Movistar p = p == nom || tengoEmpresa tl Movistar p
-- tengoEmpresa (AgregaEmpresa Tuenti nom tl) Tuenti p = p == nom || tengoEmpresa tl Tuenti p
-- tengoEmpresa (AgregaEmpresa em nom tl) e p = tengoEmpresa tl Tuenti p

-- -- Ejermplo
-- empresas = AgregaEmpresa Claro "Guille" Ninguna

-- guilleTieneClaro = tengoEmpresa empresas Claro "Guille" -- True
-- guilleTieneMovistar = tengoEmpresa empresas Movistar "Guille" -- False

-- ---- Ejercicio 3 ----------------

-- -- Tipos Ejercicio 3
-- data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b ) deriving Show
-- type NroTel = Int

-- laConcat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b

-- laConcat Vacia y = y
-- laConcat (Nodo a b l) y = Nodo a b (laConcat l y)

-- agregaLA :: ListaAsoc EmpresaTelefono NroTel -> EmpresaTelefono -> NroTel -> ListaAsoc EmpresaTelefono NroTel
-- agregaLA la em nro = laConcat la (Nodo em nro Vacia)


-- -- Ejemplo
-- laNros = Nodo Claro 1234 (Nodo Movistar 4321 Vacia)

-- laNrosMasOtroNumero = agregaLA laNros Claro 5678

-- ---- Ejercicio 4 ----------------
-- -- Tipos Ejercicio 4
-- data Arbol a = Hoja | Rama (Arbol a) a (Arbol a)

-- aBusca :: Eq a => Arbol a -> a -> Bool

-- aBusca Hoja _ = False
-- aBusca (Rama t1 v t2) x = v == x || aBusca t1 x || aBusca t2 x

-- -- Ejemplo
-- arbolito = Rama Hoja "Cosas de arboles" (Rama Hoja "Otras cosas de arboles" Hoja)
-- arbolTieneCosasDeArboles = aBusca arbolito "Cosas de arboles" -- True
-- arbolTieneOtrasCosas = aBusca arbolito "Otras cosa" -- False


type NombrePersona = String
type LugarALimpiar = String
data HayQueLimpiar = Ninguna | AgregarTarea NombrePersona LugarALimpiar HayQueLimpiar


tocaLimpiar Ninguna l p = False
tocaLimpiar (AgregarTarea p l tl) lu pe = (p==pe && lu==l) || tocaLimpiar tl lu pe 


