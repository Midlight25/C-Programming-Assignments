import random

sorting_list = []
check_counter = 0
done_sorting = False

for i in range(100):
    sorting_list.append(random.randrange(100))


while not done_sorting:

    check_counter = 0

    for i in range(len(sorting_list)):

        if (i != len(sorting_list) - 1):

            if(sorting_list[i + 1] < sorting_list[i]):
                temp = sorting_list[i + 1]
                sorting_list[i + 1] = sorting_list[i]
                sorting_list[i] = temp

            else:
                check_counter += 1

    if (check_counter == len(sorting_list) - 1):
        done_sorting = True

print(sorting_list)
