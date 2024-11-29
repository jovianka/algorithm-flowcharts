import os


class NFA:
    def __init__(self, states, input_symbols, transitions, initial_state, final_states):
        self.states = states
        self.input_symbols = input_symbols
        self.transitions = transitions
        self.initial_state = initial_state
        self.final_states = final_states
        self.current_states = {self.initial_state}

    def delta_nfa(self, current_states, symbol):
        # print(f"Current State: {current_states}, Input: {symbol}")
        next_states = list()
        for state in current_states:
            next_states.append(self.transitions[state][symbol])
        self.current_states = set().union(*next_states) # unify sets in a set

    def hat_delta_nfa(self, input_string):
        if not input_string:
            # print(self.current_states)
            result_state = self.current_states
            self.current_states = {self.initial_state} # reset
            return (
                True
                if result_state.intersection(self.final_states)
                else False
            )

        current_symbol = input_string[0]
        next_symbols = input_string[1:]

        self.delta_nfa(self.current_states, current_symbol)

        return self.hat_delta_nfa(next_symbols)