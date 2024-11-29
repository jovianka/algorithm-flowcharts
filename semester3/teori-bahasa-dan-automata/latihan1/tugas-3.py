from collections import defaultdict
from nfa import NFA
from dfa import DFA
from prettytable import PrettyTable


def nfa_to_dfa(nfa: NFA) -> DFA:

    dfa_states_list = list() # a list of lists
    dfa_states = set() # a set of strings
    dfa_transitions = defaultdict(dict) # dict of dicts
    dfa_final_states = set()

    dfa_states_list.append([nfa.initial_state])

    i = 0
    while i < len(dfa_states_list):
        current_state = list(dfa_states_list[i])
        current_state.sort()
        for symbol in nfa.input_symbols:
            if current_state == ["bin"]:
                dfa_transitions["bin"][symbol] = "bin"
            else:
                joined_current_state = "".join(current_state)
                nfa_next_states = list(set().union(*[nfa.transitions[state][symbol] for state in current_state])) # list of strings
                nfa_next_states.sort()
                if nfa_next_states == list():
                    if ["bin"] not in dfa_states_list:
                        dfa_states_list.append(["bin"])
                    dfa_transitions[joined_current_state][symbol] = "bin"
                else:
                    if nfa_next_states not in dfa_states_list:
                        dfa_states_list.append(nfa_next_states)
                    dfa_transitions[joined_current_state][symbol] = "".join(nfa_next_states)
        i += 1

    for state in dfa_states_list:
        if set(state).intersection(nfa.final_states):
            dfa_final_states.add("".join(state))
        dfa_states.add("".join(state))
    
    return DFA(dfa_states, nfa.input_symbols, dfa_transitions, nfa.initial_state, dfa_final_states)


nfa = {
    "q0": {"a": {"q1", "q2"},   "b": set()},
    "q1": {"a": set(),          "b": {"q3", "q4"}},
    "q2": {"a": set(),          "b": {"q1"}},
    "q3": {"a": set(),          "b": {"q1"}},
    "q4": {"a": {"q5"},         "b": set()},
    "q5": {"a": set(),          "b": set()},
}

nfa_instance = NFA({"q0", "q1", "q2", "q3", "q4", "q5"}, {"a", "b"}, nfa, "q0", {"q3", "q5"})
dfa_instance = nfa_to_dfa(nfa_instance)

result_table = PrettyTable()
result_table.field_names = ["Input", "NFA", "DFA"]
test_inputs = ["ab", "abb", "abbb", "aba", "abba", "abbba"]
result_table.align = "l"
data = [
    [
        x,
        nfa_instance.hat_delta_nfa(x),
        dfa_instance.hat_delta_dfa(x) ,
    ]
    for x in test_inputs
]
result_table.add_rows(data)
print("Result Table")
print(result_table, "\n")

nfa_table = PrettyTable()
nfa_table.field_names = ["state", "a", "b"]
sorted_nfa_states = list(nfa_instance.states)
sorted_nfa_states.sort()
nfa_table.align = "l"
nfa_data = [
    [
        x,
        nfa_instance.transitions[x]["a"],
        nfa_instance.transitions[x]["b"],
    ]
    for x in sorted_nfa_states
]
nfa_table.add_rows(nfa_data)
print("NFA")
print(nfa_table, "\n")

dfa_table = PrettyTable()
dfa_table.field_names = ["state", "a", "b"]
sorted_dfa_states = list(dfa_instance.states)
sorted_dfa_states.sort()
print(dfa_instance.transitions)
dfa_table.align = "l"
dfa_data = [
    [
        x,
        dfa_instance.transitions[x]["a"],
        dfa_instance.transitions[x]["b"],
    ]
    for x in sorted_dfa_states
]
dfa_table.add_rows(dfa_data)
print("DFA")
print(dfa_table, "\n")
