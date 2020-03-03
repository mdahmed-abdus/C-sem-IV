from operator import itemgetter

print("NOTE: SJF")
print("1. Arrival time of at least one process must be 0")
print("2. CPU must never be idle")

temp_processes = []
no_of_processes = int(input("\nEnter the number of processes: "))
unit = input("Enter the time unit: ")

for i in range(no_of_processes):
    print("\nFor process number:", i)

    process_id = int(input("Enter the process id: "))
    arrival_time = int(input("Enter the arrival time: "))
    burst_time = int(input("Enter the burst time: "))

    temp_processes.append({
        "process_id": process_id,
        "arrival_time": arrival_time,
        "burst_time": burst_time
    })

# separating processes if arrival == 0
at_zero_processes = []
processes = []

for i in range(no_of_processes):
    if temp_processes[i].get("arrival_time") == 0:
        at_zero_processes.append(temp_processes[i])
    else:
        processes.append(temp_processes[i])

# sorting processes with arrival time == 0, based on burst time in reverse
at_zero_processes = sorted(
    at_zero_processes, key=itemgetter("burst_time"), reverse=True
)

# sorting processes with arrival time != 0, based on burst time
processes = sorted(processes, key=itemgetter("burst_time"))

# adding processes with arrival time 0 to rest of the list
for i in range(len(at_zero_processes)):
    processes.insert(0, at_zero_processes[i])

# calculate start, wait, turn around time for processes 0
start_time = processes[0].get("arrival_time")
turn_around_time = processes[0].get("burst_time")

processes[0].update({
    "start_time": start_time,
    "wait_time": 0,
    "turn_around_time": turn_around_time
})

total_wait_time = 0
total_turn_around_time = turn_around_time

# calculate start, wait, turn around time for other processes
for i in range(1, no_of_processes):
    start_time = processes[i - 1].get("start_time") + \
        processes[i - 1].get("burst_time")
    wait_time = start_time - processes[i].get("arrival_time")
    turn_around_time = wait_time + processes[i].get("burst_time")

    processes[i].update({
        "start_time": start_time,
        "wait_time": wait_time,
        "turn_around_time": turn_around_time
    })

    total_wait_time += wait_time
    total_turn_around_time += turn_around_time

avg_wait_time = total_wait_time / no_of_processes
avg_turn_around_time = total_turn_around_time / no_of_processes

# display gnatt chart
print("\nGnatt chart")
for i in range(no_of_processes):
    if i == no_of_processes - 1:
        print(
            f"{processes[i].get('start_time')}"
            f"<P[{processes[i].get('process_id')}]>"
            f"{processes[i].get('start_time') + processes[i].get('burst_time')}"
        )
    else:
        print(
            f"{processes[i].get('start_time')}"
            f"<P[{processes[i].get('process_id')}]>", end=""
        )

# display table
print("\nProcess ID\tStart time\tArrival time\tWaiting time\tTurn around time")
for process in processes:
    process_id = process.get("process_id")
    start_time = process.get("start_time")
    arrival_time = process.get("arrival_time")
    wait_time = process.get("wait_time")
    turn_around_time = process.get("turn_around_time")
    print(f"{process_id}\t\t{start_time}\t\t{arrival_time}\t\t{wait_time}\t\t{turn_around_time}")

# display answers
print("\nTotal waiting time:", total_wait_time, unit)
print("Total turn around time:", total_turn_around_time, unit)
print("Average waiting time:", round(avg_wait_time, 2), unit)
print("Average turn around time:", round(avg_turn_around_time, 2), unit)
