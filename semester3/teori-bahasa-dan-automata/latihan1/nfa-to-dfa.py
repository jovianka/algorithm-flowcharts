from collections import defaultdict
from nfa import NFA
from dfa import DFA


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