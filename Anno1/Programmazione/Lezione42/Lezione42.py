import pandas as pd

df_t = pd.read_excel('triathlon.xls')

df_t['trs'] = pd.to_timedelta(df_t['trs']) #trasforma l'input (e.g. una colonna) come una nuova colonna di tipo timedelta.
df_t['trb'] = pd.to_timedelta(df_t['trb'])
df_t['trr'] = pd.to_timedelta(df_t['trr'])

df_t['time'] = df_t['trs'] + df_t['trb'] + df_t['trr']

df_t.sort_values(by = 'time', ascending= True)
print(df_t['COGNOME', 'M/F' 'time'])

print(df_t[df_t['M/F'] == 'F']) #classifica esclusivamente femminile!

#ESERCIZIO: aggiungi a questo dataframe una colonna di posizione di arrivo in base alla categoria di appartenenza, tenendo conto anche se è un uomo o una donna. (Facoltativo, per la seconda parte.)