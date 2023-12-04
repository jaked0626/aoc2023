
def is_possible(line: str, balls: dict[str, int]) -> int:
    balls_max = {}
    game, rounds = line.split(":")
    score = int(game.split()[-1])
    rounds = rounds.split(";")
    for round_ in rounds:
        draws = round_.split(",")
        for draw in draws:
            num, color = draw.split()
            if int(num) > balls.get(color, 0):
                return 0

    return score


def main() -> None:
    with open("./day2/input.txt", "r") as f:
        lines = f.readlines()
    
    sum_ = 0
    balls = {
        "red": 12,
        "blue": 14,
        "green": 13,
    }
    for line in lines:
        score = is_possible(line, balls)
        sum_ += score

    print(sum_)
    return 0 

if __name__ == "__main__":
    main()