from matplotlib import pyplot as plt
nominees = ['nominee1  ' ,  'nominee2  ',   'nominee3  ']
percentage_of_the_votes= [10, 20, 93]
plt.figure(figsize=(30,10 ))
plt.subplot(131)
plt.bar(nominees, percentage_of_the_votes)
plt.suptitle('chart for the vote polling')
plt.show()