import pandas as pd

df = pd.DataFrame()

#questo è un dataframe, una tabella con un indice e delle colonne. Posso anche dargli un nome. Stessa sintassi del dizionario.

df['ColA'] = [8, 2, 1, 9]
df['ColB'] = [12, 21, 10, 9.8]

print(df.shape) #ci fornisce un'informazione sulla struttura del dataframe, nel formato (righe, colonne).

#possiamo indicizzare la tupla fornitaci del dfshape.

num_righe = df.shape[0]
num_colonne = df.shape[1]

print(df.describe()) #ci fornisce alcune informazioni sul Dataframe.

print(df['ColA'].min()) 
print(df['ColB'].max())
print(df['ColB'].mean())

#le colonne devono avere lo STESSO TIPO all'interno. In caso di divergenza, si cerca il tipo che li descrive tutti al meglio.

df['ColC'] = [0, 2.71, '3.14', 'alessio']

#ricordati che le colonne devono avere lo stesso numero di elementi!


#In[]

#sono supportate le operazioni fra colonne, così come l'assegnazione del risultato ad una nuova colonna.
df['ColD']= print(2*df['ColA'])
df['ColE'] = df['ColA'] + df['ColB']

#In[]

#possiamo anche filtrare le colonne condizionalmente.

print(df['ColA'] > 5) #ritornerà una colonna di booleani che verifichino se la condizione imposta è true o false per ciascun elemento.

df_f= df[df['ColA'] > 5]

print (df_f)


# In[]

print(df.columns)

df.columns = ['A', 'B', 'C', 'D', 'E'] #possiamo riassegnare i nomi delle varie colonne del Dataframe, ma le dobbiamo rinominare tutte le colonne. Non possiamo accedere ad un singolo elemento.

print(df.columns)

# In[]

print(df_f.index)

df_f.index = range(df_f.shape[0]) #questo mi prenderà il valore di righe del DataFrame, che possiamo quindi usare per creare un range di indici consecutivi.


#In[]

print(df.iloc[0:2]) #permette di fare slicing delle righe menzionate nello slicing, da 0 a n-1. 

#l'iloc è supportato su righe, colonne, e righe e colonne contemporaneamente.

print(df.iloc[0:2, 1:3])
print(df.iloc[:, 1:3])
print(df.iloc [:, 'B' : 'D']) #supporta anche l'indicizzazione per nome delle colonne.

print(df.loc[:, 'B' : 'D']) #a differenza dell'iloc, loc prende anche l'ultima riga menzionata nello slicing. Quindi 0 a n.

# In[]
import pandas as pd
#possiamo importare da altri file per l'edit e la lettura.

df_c = pd.read_csv('2019fifa-wwc-c.csv')
print(df_c)

df_c['Score_diff'] = df_c['Score1'] - df_c['Score2']

print(df_c)

team = 'Italy'
df_t = df_c[ (df_c['Team1'] == team) | (df_c['Team2'] == team) ]

punti_t= 0
for _, x in df_t.iterrows():
    if(x['Team1'] == team):#essendo x una variabile riga vera e propria, posso accedere ad un suo elemento con lo slicing.
        if x['Score1'] > x['Score2']:
            punti_t += 3
    elif x['Team2'] == team:
        if x['Score2'] > x['Score1']:
            punti_t += 3
    elif x['Score2'] == x['Score1']:
        punti_t += 1

print (punti_t)
#nota che il tipo di una colonna è serious, un data type esclusivo a Pandas.
         
# In[]

classifica = pd.DataFrame()

list_teams = list(df_c['Team1']) + list(df_c['Team2'])

l = []

for t in list_teams:
    if t not in l:
        l.append(t)

#operazione a costo quadratico! Pretty fucking bad.


# In[]


dict_teams = {}

for t in list_teams:
    if t not in dict_teams:
        dict_teams[t] = None

classifica ['Teams'] = dict_teams.keys()

# In[]
import pandas as pd
classifica = pd.DataFrame()
scores = []

for team in classifica['Team']:
    df_t = df_c[ (df_c['Team1'] == team) | (df_c['Team2'] == team) ]

    punti_t = 0
    for _, x in df_t.iterrows():
        if x['Team1'] == team:
            if x['Score1'] > x['Score2']:
                punti_t += 3
        if x['Team2'] == team:
            if x['Score2'] > x['Score1']:
                punti_t += 3
        if x['Score2'] == x['Score1']:
            punti_t += 1

    scores.append(punti_t)


classifica['Scores'] = scores

classifica = classifica.sort_values(by='Scores', ascending=False)

print(classifica)

# %%
