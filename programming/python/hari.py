page_faults = 0
pages = int(input("Enter the number of pages"))
reference_string = input("Enter the reference string")
frames = int(input("Enter the number of frames"))
temp = [0 for i in range(frames)]
for i in range(frames):
    temp[i] = -1
for i in range(pages):
    s = 0
    for j in range(frames):
        if reference_string[i] == temp[j]:
            s += 1
            page_faults -= 1

    page_faults += 1
    if s == 0 and page_faults <= frames:
        temp[i] = reference_string[i]
    elif s == 0:
        temp[(page_faults - 1) % frames] = reference_string[i]
    for i in range(frames):
        print(temp[i], end=" ")

print("\nPage Faults:", page_faults)
