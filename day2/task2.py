import functools

def power_of_game(line: str) -> int:
    balls_max = {}
    rounds = line.split(":")[1]
    rounds = rounds.split(";")
    for round_ in rounds:
        draws = round_.split(",")
        for draw in draws:
            num, color = draw.split()
            balls_max[color] = max(int(num), balls_max.get(color, 0))
    
    score = functools.reduce(lambda a, b: a * b, balls_max.values())
    print(score)
    return score


def main() -> None:
    with open("./day2/input.txt", "r") as f:
        lines = f.readlines()
    
    sum_ = 0
    for line in lines:
        score = power_of_game(line)
        sum_ += score

    print(sum_)
    return 0 

if __name__ == "__main__":
    main()