# Simulación de navegación de páginas web

pila = []
pilaHistorial = []
pag = 0

def nueva_pag():
    global pag
    pag += 1
    pila.append("Página " + str(pag))
    pilaHistorial.clear()
    print("Nueva:", pila[-1])

def retroceder():
    if len(pila) > 1:
        pilaHistorial.append(pila.pop())
        print("Retrocediste a:", pila[-1])
    else:
        print("No hay páginas para retroceder")

def adelantar():
    if pilaHistorial:
        pila.append(pilaHistorial.pop())
        print("Avanzaste a:", pila[-1])
    else:
        print("No hay páginas para adelantar")

def pagina_actual():
    print("Página actual:", pila[-1] if pila else "No hay páginas")
