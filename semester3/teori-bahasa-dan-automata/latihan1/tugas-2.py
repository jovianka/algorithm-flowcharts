import os
import itertools


class NFA:
    def __init__(self, states, input_symbols, transition, initial_state, final_states):
        self.states = states
        self.input_symbols = input_symbols
        self.transition = transition
        self.initial_state = initial_state
        self.final_states = final_states
        self.current_states = {self.initial_state}

    def delta_nfa(self, current_states, symbol):
        print(f"Current State: {current_states}, Input: {symbol}")
        next_states = list()
        for state in current_states:
            next_states.append(self.transition[state][symbol])
        self.current_states = set.union(*next_states) # unify sets in a set

    def hat_delta_nfa(self, input_string):
        if not input_string:
            return (
                True
                if self.current_states.intersection(self.final_states) != set()
                else False
            )

        current_symbol = input_string[0]
        next_symbols = input_string[1:]

        self.delta_nfa(self.current_states, current_symbol)

        return self.hat_delta_nfa(next_symbols)


nfa_l1 = {
    0: {"0": set(), "1": {1}},
    1: {"0": {2}, "1": set()},
    2: {"0": {2, 3}, "1": {2}},
    3: {"0": set(), "1": {4}},
    4: {"0": set(), "1": set()},
}
accept_l1 = {4}

nfa_l2 = {
    0: {"0": {0, 1}, "1": {0}},
    1: {"0": {2}, "1": set()},
    2: {"0": {3}, "1": set()},
    3: {"0": {3}, "1": {3, 4}},
    4: {"0": set(), "1": set()},
}
accept_l2 = {4}

nfa_l3 = {
    0: {"0": {3}, "1": {1}},
    1: {"0": {1, 2}, "1": {1}},
    2: {"0": set(), "1": set()},
    3: {"0": {3}, "1": {3, 4}},
    4: {"0": set(), "1": set()},
}
accept_l3 = {2, 4}

nfa_l4 = {
    0: {"0": {1}, "1": {6}},
    1: {"0": {1}, "1": {1, 2}},
    2: {"0": {3}, "1": set()},
    3: {"0": set(), "1": {4}},
    4: {"0": {4, 5}, "1": {4}},
    5: {"0": set(), "1": set()},
    6: {"0": {7}, "1": {6}},
    7: {"0": {9}, "1": {8}},
    8: {"0": {10}, "1": {8}},
    9: {"0": {9}, "1": {6}},
    10: {"0": {10}, "1": {8}},
}
accept_l4 = {5, 8}


# memilih bahasa
def main():
    os.system("clear")

    print("Pilih Bahasa nfa:")
    print("1. L1: semua string yang berawalan 10 dan berakhiran 01")
    print("2. L2: semua string yang mengandung subtring 000 dan berakhiran 1")
    print(
        "3. L3: semua string yang berawalan dan berakhiran dengan simbol yang berbeda"
    )
    print(
        "4. L4: semua string yang berawalan dan berakhiran dengan simbol yang sama dan mengandung substring 101"
    )

    choice = input("Masukkan pilihan (1-4): ")
    input_string = input("Masukkan string 0 dan 1: ")

    if choice == "1":
        nfa_instance = NFA({0, 1, 2, 3, 4, 5}, {"0", "1"}, nfa_l1, 0, accept_l1)
        result = nfa_instance.hat_delta_nfa(input_string)

        if result == True:
            print(f"Final state: {nfa_instance.current_states}")
            print(f"'{input_string}' Accepted")
        else:
            print(f"Final state: {nfa_instance.current_states}")
            print(f"'{input_string}' Rejected")
    elif choice == "2":
        nfa_instance = NFA({0, 1, 2, 3, 4}, {"0", "1"}, nfa_l2, 0, accept_l2)
        result = nfa_instance.hat_delta_nfa(input_string)

        if result == True:
            print(f"Final state: {nfa_instance.current_states}")
            print(f"'{input_string}' Accepted")
        else:
            print(f"Final state: {nfa_instance.current_states}")
            print(f"'{input_string}' Rejected")
    elif choice == "3":
        nfa_instance = NFA({0, 1, 2, 3, 4}, {"0", "1"}, nfa_l3, 0, accept_l3)
        result = nfa_instance.hat_delta_nfa(input_string)

        if result == True:
            print(f"Final state: {nfa_instance.current_states}")
            print(f"'{input_string}' Accepted")
        else:
            print(f"Final state: {nfa_instance.current_states}")
            print(f"'{input_string}' Rejected")
    elif choice == "4":
        nfa_instance = NFA(
            {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {"0", "1"}, nfa_l4, 0, accept_l4
        )
        result = nfa_instance.hat_delta_nfa(input_string)

        if result == True:
            print(f"Final state: {nfa_instance.current_states}")
            print(f"'{input_string}' Accepted")
        else:
            print(f"Final state: {nfa_instance.current_states}")
            print(f"'{input_string}' Rejected")


if __name__ == "__main__":
    main()
