def canCompleteCircuit(gas,cost):
    index = 0
    remaining = 0
    prev_remaining = 0
    for i in range(len(gas)):
        remaining += gas[i] - cost[i]
        if remaining < 0:
            index = i + 1
            prev_remaining += remaining
            remaining = 0
    if index == len(gas) or remaining + prev_remaining < 0:
        return -1
    return index
print(canCompleteCircuit([2,3,4],[3,4,3]))