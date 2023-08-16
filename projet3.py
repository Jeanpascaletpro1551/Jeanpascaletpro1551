import time
import matplotlib.pyplot as plt

print("Bienvenue dans le programme de création de sondage")
time.sleep(1)

print("Quelle est la question que vous voulez poser?")
question = input(">")
time.sleep(1)

print("Combien de réponses voulez-vous avoir pour cette question?")
n = int(input(">"))
time.sleep(1)

liste = []
dictionnaire = {}
n1 = 1
print("Veuillez entrer les réponses:")
while n1 <= n:
    reponse = input("Réponse {} : ".format(n1))
    liste.append(reponse)
    n1 += 1

print("Veuillez saisir le nombre de réponses enregistrées:")
for rep in liste:
    valeur = int(input("Pour la réponse '{}' le nombre est : ".format(rep)))
    dictionnaire[rep] = valeur
print(" voici avec les analyses le resultat de votre sondage ")
time.sleep(2)
# resultat du sondage sous forme de diagramme
labels = dictionnaire.keys()
sizes = dictionnaire.values()

plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=140)
plt.axis('equal')  # Assure que le graphique est un cercle plutôt qu'une ellipse
plt.title(question)
plt.show()

