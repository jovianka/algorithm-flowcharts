import os


class DFA:
    def __init__(self, states, input_symbols, transition, initial_state, final_states):
        self.states = states
        self.input_symbols = input_symbols
        self.transition = transition
        self.initial_state = initial_state
        self.final_states = final_states
        self.current_state = self.initial_state

    def delta_dfa(self, current_state, symbol):
        print(
            f"Current State: {current_state}, Input: {symbol} -> Next State: {self.transition[current_state][symbol]}"
        )
        self.current_state = self.transition[current_state][symbol]

    def hat_delta_dfa(self, input_string):
        if not input_string:
            return self.current_state in self.final_states

        current_symbol = input_string[0]
        next_symbols = input_string[1:]

        self.delta_dfa(self.current_state, current_symbol)

        return self.hat_delta_dfa(next_symbols)


dfa_l1 = {
    0: {"0": 1, "1": 2},
    1: {"0": 1, "1": 1},
    2: {"0": 3, "1": 1},
    3: {"0": 3, "1": 4},
    4: {"0": 3, "1": 5},
    5: {"0": 3, "1": 5},
}
accept_l1 = {4}

dfa_l2 = {
    0: {"0": 1, "1": 0},
    1: {"0": 2, "1": 0},
    2: {"0": 3, "1": 0},
    3: {"0": 3, "1": 4},
    4: {"0": 3, "1": 4},
}
accept_l2 = {4}

dfa_l3 = {
    0: {"0": 3, "1": 1},
    1: {"0": 2, "1": 1},
    2: {"0": 2, "1": 1},
    3: {"0": 3, "1": 4},
    4: {"0": 3, "1": 4},
}
accept_l3 = {2, 4}

dfa_l4 = {
    0: {"0": 4, "1": 1},
    1: {"0": 2, "1": 1},
    2: {"0": 1, "1": 3},
    3: {"0": 2, "1": 3},
    4: {"0": 4, "1": 5},
    5: {"0": 6, "1": 5},
    6: {"0": 4, "1": 7},
    7: {"0": 8, "1": 7},
    8: {"0": 8, "1": 7},
}
accept_l4 = {3, 8}


# memilih bahasa
def main():
    os.system("clear")

    print("Pilih Bahasa DFA:")
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
        dfa_instance = DFA({0, 1, 2, 3, 4, 5}, {"0", "1"}, dfa_l1, 0, accept_l1)
        result = dfa_instance.hat_delta_dfa(input_string)
        if result == True:
            print(f"'{input_string}' Accepted")
    elif choice == "2":
        dfa_instance = DFA({0, 1, 2, 3, 4}, {"0", "1"}, dfa_l2, 0, accept_l2)
        result = dfa_instance.hat_delta_dfa(input_string)
        if result == True:
            print(f"'{input_string}' Accepted")
    elif choice == "3":
        dfa_instance = DFA({0, 1, 2, 3, 4}, {"0", "1"}, dfa_l3, 0, accept_l3)
        result = dfa_instance.hat_delta_dfa(input_string)
        if result == True:
            print(f"'{input_string}' Accepted")
    elif choice == "4":
        dfa_instance = DFA(
            {0, 1, 2, 3, 4, 5, 6, 7, 8}, {"0", "1"}, dfa_l4, 0, accept_l4
        )
        result = dfa_instance.hat_delta_dfa(input_string)
        if result == True:
            print(f"'{input_string}' Accepted")


if __name__ == "__main__":
    main()
