grafo = []

def novoGrafo(n_vertice):
    N = n_vertice
    for i in range(0, N):
        linha = list()
        for j in range(0, N):
            linha.append(0)
        grafo.append(linha)

############## AULA 05/04 ##############
def diagonalPrincipal(grafo,n_vertices):
    A = grafo
    for i in range(0,n_vertices):
        print(A[i][i])

def mostraCantos(grafo,n_vertices):
    A = grafo
    print(A[0][0])
    print(A[n_vertices-1][0])
    print(A[0][n_vertices-1])
    print(A[n_vertices-1][n_vertices-1])


novoGrafo(5)
print("-="*10,"Mostra a diagonal principal da matriz","-="*10)
diagonalPrincipal(grafo,5)
print("-="*10,"Mostra os quatro cantos da matriz","-="*10)
mostraCantos(grafo,5)

