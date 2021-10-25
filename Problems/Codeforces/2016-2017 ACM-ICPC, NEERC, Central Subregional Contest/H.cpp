escrita = open('output.txt','w')
leitura = open('input.txt','r')

for linha in leitura:
    n = int(linha)

resp = 8

aux = 1

while(aux < n and aux < 9):
    resp*=9
    aux+=1

while(aux < n):
    resp*=10
    aux+=1

escrita.write(str(resp))
escrita.close()
