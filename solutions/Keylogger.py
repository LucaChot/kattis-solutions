sounds = {"clank" : 'a', "bong" : 'b', "click" : 'c', "tap" : 'd', "poing" : 'e', "clonk" : 'f', "clack" : 'g', "ping" : 'h',
        "tip" : 'i', "cloing" : 'j', "tic" : 'k', "cling" : 'l', "bing" : 'm', "pong" : 'n', "clang" : 'o', "pang" : 'p',
        "clong" : 'q', "tac" : 'r', "boing" : 's', "boink" : 't', "cloink" : 'u', "rattle" : 'v', "clock" : 'w', "toc" : 'x',
        "clink" : 'y', "tuc" : 'z', "whack" : ' '}

def main():
    num = int(input())
    string = ""
    cap = False
    shift = False
    for i in range(num):
        sound = str(input())
        if sound in sounds.keys():
            character = sounds[sound]
            if (cap and not shift) or (shift and not cap):
                character = character.upper()
            string = string + character
        elif sound == "pop" and len(string) > 0:
            string = string[:-1]
        elif sound == "bump":
            cap = not cap
        elif sound == "dink":
            shift = True
        elif sound == "thumb":
            shift = False
    print(string)