# In[]
import pandas as pd

df_c = pd.read_csv('2019fifa-wwc-c.csv')
df_c['Score_diff'] = df_c['Score1'] - df_c['Score2']
print (df_c)
classifica = pd.DataFrame()

list_teams = list(df_c['Team1']) + list(df_c['Team2'])

dict_teams = {}

for t in list_teams:
    if t not in dict_teams: # O(1)
        dict_teams[t] = None
    

classifica['Team'] = dict_teams.keys()


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

totalscores = []
for team in classifica['Team']:
    df_t = df_c[ (df_c['Team1'] == team) | (df_c['Team2'] == team) ]
    punti_totali = 0
    for _, x in df_t.iterrows():
        if x['Team1'] == team:
            punti_totali += x['Score1'] - x['Score2']
        elif x['Team2'] == team:
            punti_totali += x['Score2'] - x['Score1']


    totalscores.append(punti_totali)
    
classifica['Punti Totali'] = punti_totali
classifica = classifica.sort_values(by='Scores', ascending=False)
print(classifica)

dict_score_diff = {}

for _, x in df_t.iterrows():
    score_diff = x['Score1'] - x['Score2']
    try:
        dict_score_diff[x['Team1']] += score_diff
    except KeyError:
        dict_score_diff[x['Team1']] = score_diff
    
    dict_score_diff[x['Team2']] = dict_score_diff.get(x['Team2'], 0) +\
    score_diff


list_score_diff = []

for t in classifica['Team']:
    list_score_diff.append(dict_score_diff[t])

classifica['Score_diff'] = list_score_diff
classifica = classifica.sort_values(by=['Scores', 'Score_diff'], ascending=False)

# In[]


    

