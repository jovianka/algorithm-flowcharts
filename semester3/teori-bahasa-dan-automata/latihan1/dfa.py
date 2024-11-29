import os


class DFA:
    def __init__(self, states, input_symbols, transitions, initial_state, final_states):
        self.states = states
        self.input_symbols = input_symbols
        self.transitions = transitions
        self.initial_state = initial_state
        self.final_states = final_states
        self.current_state = self.initial_state

    def delta_dfa(self, current_state, symbol):
        # print(
        #     f"Current State: {current_state}, Input: {symbol} -> Next State: {self.transitions[current_state][symbol]}"
        # )
        print(self.transitions, current_state, symbol)
        self.current_state = self.transitions[current_state][symbol]

    def hat_delta_dfa(self, input_string):
        if not input_string:
            result_state = self.current_state
            self.current_state = self.initial_state # reset
            return result_state in self.final_states

        current_symbol = input_string[0]
        next_symbols = input_string[1:]

        self.delta_dfa(self.current_state, current_symbol)

        return self.hat_delta_dfa(next_symbols)
