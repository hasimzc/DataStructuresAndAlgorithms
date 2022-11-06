'''
                 Problem Definition
Given a circular list of gas stations, where we can go from a station i to the station i+1, and the last one goes back to the first one,
find the index of the station from where we start to be able to traverse all the stations and go back to the initial one without running
out of gas.
'''

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
