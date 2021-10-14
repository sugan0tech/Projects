import requests
for i in range(100):
    response = requests.get(f"http://localhost:1337/do/{i}/'whola'")
    print(response)