Considerá la función queHace :: Int → Int → [Int] → Int especificada como
```haskell
queHace.b.a.xs = 〈 Max p, q : 0 ≤ p ≤ q < #xs ∧ 〈 ∀i : p ≤ i < q : b < xs!i < a 〉 : q − p 〉

a) Esta funcion devuelve el tamaño del segmento más grande tal que sus elementos esten en (a,b)

b) Transformala en una que use segmentos:

queHace.b.a.xs = 〈 Max as,bs,cs : take.(#xs-1).xs=as++bs++cs  ∧ <Ai : 0<=i<#bs : b< bs!i < a > : #bs 〉

-- Modularizo

queHace.b.a.xs = 〈 Max as,bs,cs : take.(#xs-1).xs=as++bs++cs  ∧ todosEntre.b.a.bs : #bs 〉

c) Derivala

-- Induccion sobre xs
-- Caso base, por definición de take, nuestro caso base es la lista con un elemento.

queHace.b.a.[x] = 〈 Max as,bs,cs : take.(#xs-1).[] =as++bs++cs  ∧ todosEntre.b.a.bs : #bs 〉

queHace.b.a.[x] = 〈 Max as,bs,cs : take.(1-1).[] =as++bs++cs  ∧ todosEntre.b.a.bs : #bs 〉

queHace.b.a.[x] = 〈 Max as,bs,cs : take.(0).[] =as++bs++cs  ∧ todosEntre.b.a.bs : #bs 〉

queHace.b.a.[x] = 〈 Max as,bs,cs : []=as++bs++cs  ∧ todosEntre.b.a.bs : #bs 〉

-- Elimino variables
queHace.b.a.[x] = 〈 Max bs : []=bs  ∧ todosEntre.b.a.bs : #bs 〉

queHace.b.a.[x] = 〈 Max bs : []=bs  ∧ True : #bs 〉

-- Rango unitario y cardinal
queHace.b.a.[x] = 0

-- Caso inductivo

queHace.b.a.(k:ks) 

= 

< Max as,bs,cs : take.(k:ks).(#(k:ks)-1)=as++bs++cs  ∧ todosEntre.b.a.bs : #bs >

-- Take y cardinal

< Max as,bs,cs : k:take.(ks).(#(ks)-1)=as++bs++cs  ∧ todosEntre.b.a.bs : #bs >

-- Tercero excluido

< Max as,bs,cs : k:take.(ks).(#(ks)-1)=as++bs++cs  /\ as=[] V as!=[] /\ todosEntre.b.a.bs : #bs >

-- Parto el rango

< Max as,bs,cs : k:take.(ks).(#(ks)-1)=as++bs++cs  /\ as=[] /\ todosEntre.b.a.bs : #bs > max < Max as,bs,cs : k:take.(ks).(#(ks)-1)=as++bs++cs  /\ as!=[] /\ todosEntre.b.a.bs : #bs >

-- Eliminacion de variable as y propiedades de concat

< Max bs,cs : k:take.(ks).(#(ks)-1)=bs++cs  /\ todosEntre.b.a.bs : #bs > max < Max as,bs,cs : k:take.(ks).(#(ks)-1)=as++bs++cs  /\ as!=[] /\ todosEntre.b.a.bs : #bs >

-- Take

< Max bs,cs : take.(k:ks).(#(k:ks)-1)=bs++cs /\ todosEntre.b.a.bs : #bs > max < Max as,bs,cs : k:take.(ks).(#(ks)-1)=as++bs++cs  /\ as!=[] /\ todosEntre.b.a.bs : #bs >

-- Modularizo

maxPrefEntre.b.a.(k:ks) max < Max as,bs,cs : k:take.(ks).(#(ks)-1)=as++bs++cs  /\ as!=[] /\ todosEntre.b.a.bs : #bs >

-- Cambio de variable as -> a:as

maxPrefEntre.(k:ks) max < Max a',as,bs,cs : k:take.(ks).(#(ks)-1)=(a':as)++bs++cs /\ todosEntre.b.a.bs : #bs >

-- Def de concat 
 
maxPrefEntre.(k:ks) max < Max a',as,bs,cs : k:take.(ks).(#(ks)-1)=a':(as++bs++cs) /\ todosEntre.b.a.bs : #bs >

-- Propiedad de listas

maxPrefEntre.(k:ks) max < Max a',as,bs,cs : k = a' /\ take.(ks).(#(ks)-1)=as++bs++cs /\ todosEntre.b.a.bs : #bs >

-- Eliminacion de variable

maxPrefEntre.(k:ks) max < Max as,bs,cs : take.(ks).(#(ks)-1)=as++bs++cs /\ todosEntre.b.a.bs : #bs >

-- Hip

maxPrefEntre.(k:ks) max queHace.b.a.ks

-- Derivamos maxPrefEntre

-- Especificacion:
maxPrefEntre.b.a.ks = < Max bs,cs : take.(ks).(#(ks)-1)=bs++cs  /\ todosEntre.b.a.bs : #bs >

-- Caso base
< Max bs,cs : take.[x].(#[x]-1)=bs++cs  /\ todosEntre.b.a.bs : #bs >

--xd

< Max bs,cs : take.[x].(1-1)=bs++cs  /\ todosEntre.b.a.bs : #bs >

-- Take

< Max bs,cs : []=bs++cs  /\ todosEntre.b.a.bs : #bs >

-- Rango unitario y cardinal

0

-- Caso inductivo

< Max bs,cs : take.(k:ks).(#(k:ks)-1)=bs++cs  /\ todosEntre.b.a.bs : #bs >

-- Take y cardinal

< Max bs,cs : k:take.(ks).(#(ks)-1)=bs++cs  /\ todosEntre.b.a.bs : #bs >

-- Tercero excluido y partimos rango // recordar pasos

< Max bs,cs : k:take.(ks).(#(ks)-1)=bs++cs /\ bs = [] /\ todosEntre.b.a.bs : #bs > max < Max bs,cs : k:take.(ks).(#(ks)-1)=bs++cs /\ bs!=[] /\ todosEntre.b.a.bs : #bs >

-- Eliminacion

< Max cs : k:take.(ks).(#(ks)-1)=cs /\ todosEntre.b.a.[] : #[] > max < Max bs,cs : k:take.(ks).(#(ks)-1)=bs++cs /\ bs!=[] /\ todosEntre.b.a.bs : #bs >

-- Rango unitario y cardinal

0 max < Max bs,cs : k:take.(ks).(#(ks)-1)=bs++cs /\ bs!=[] /\ todosEntre.b.a.bs : #bs >

-- Neutro(?

< Max bs,cs : k:take.(ks).(#(ks)-1)=bs++cs /\ bs!=[] /\ todosEntre.b.a.bs : #bs >

-- Cambio de variable y eso

< Max b',bs,cs : k = b' take.(ks).(#(ks)-1)=bs++cs /\ todosEntre.b.a.(b':bs) : #(b':bs) >

-- Eliminacion

< Max b',bs,cs : take.(ks).(#(ks)-1)=bs++cs /\ todosEntre.b.a.(k':bs) : #(k:bs) >

-- Propiedad de listas

< Max b',bs,cs : take.(ks).(#(ks)-1)=bs++cs /\ todosEntre.b.a.([k]++bs) : #([k]:bs) >

-- Generalizamos maxPrefEntre

maxPrefEntreG.b.a.ks.ps = < Max bs,cs : take.(ks).(#(ks)-1)=bs++cs  /\ todosEntre.b.a.(ps++bs) : #(ps++bs) >

-- Caso base

maxPrefEntreG.b.a.[].ps = 

< Max bs,cs : take.([]).(#([])-1)=bs++cs  /\ todosEntre.b.a.(ps++bs) : #(ps++bs) >

-- Take 

< Max bs,cs : []=bs++cs  /\ todosEntre.b.a.(ps++bs) : #(ps++bs) >

-- Eliminacion

< Max : todosEntre.b.a.(ps) : #(ps) >

-- Rango unitario y condicion

(
 todosEntre.b.a.(ps) -> #(ps)
 !todosEntre.b.a.(ps) -> 0
) + p

-- Caso inductivo

maxPrefEntreG.b.a.(k:ks).ps = 

< Max bs,cs : take.((k:ks)).(#(k:ks)-1)=bs++cs  /\ todosEntre.b.a.(ps++bs) : #(ps++bs) >

-- Take y cardinal

< Max bs,cs : k:take.((ks)).(#ks-1)=bs++cs  /\ todosEntre.b.a.(ps++bs) : #(ps++bs) >

-- Partimos el rango

< Max bs,cs : k:take.((ks)).(#ks-1)=bs++cs /\ bs=[] /\ todosEntre.b.a.(ps++bs) : #(ps++bs) > max < Max bs,cs : k:take.((ks)).(#ks-1)=bs++cs /\ bs!=[] /\ todosEntre.b.a.(ps++bs) : #(ps++bs) >

-- Eliminacion

< Max : todosEntre.b.a.(ps) : #(ps) > max < Max bs,cs : k:take.((ks)).(#ks-1)=bs++cs /\ bs!=[] /\ todosEntre.b.a.(ps++bs) : #(ps++bs) >

-- Rango unitario y condicion

(todosEntre.b.a.ps -> #ps, !todosEntre.b.a.ps -> 0) max < Max bs,cs : k:take.((ks)).(#ks-1)=bs++cs /\ bs!=[] /\ todosEntre.b.a.(ps++bs) : #(ps++bs) >

-- Una banda de pasos

(todosEntre.b.a.ps -> #ps, !todosEntre.b.a.ps -> 0) max < Max b', bs,cs : k = b' /\ take.((ks)).(#ks-1)=bs++cs /\ todosEntre.b.a.(ps++(b':bs)) : #(ps++(b':bs)) >

-- Eliminacion

(todosEntre.b.a.ps -> #ps, !todosEntre.b.a.ps -> 0) max < Max bs,cs : take.((ks)).(#ks-1)=bs++cs /\ todosEntre.b.a.(ps++(k:bs)) : #(ps++(k:bs)) >

-- Listas

(todosEntre.b.a.ps -> #ps, !todosEntre.b.a.ps -> 0) max < Max bs,cs : take.((ks)).(#ks-1)=bs++cs /\ todosEntre.b.a.(ps++[k]++bs) : #(ps++[k]++bs) >

-- Hip

(todosEntre.b.a.ps -> #ps, !todosEntre.b.a.ps -> 0) max maxPrefEntreG.b.a.ks.(ps++[k])
```
