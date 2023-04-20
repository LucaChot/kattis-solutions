num_entries = int(input())
users = {}
for i in range(num_entries):
    action, user = str(input()).split(" ")
    if action == 'entry':
        message = user + ' entered'
        if (users.setdefault(user, False)):
            message += ' (ANOMALY)'
        users[user] = True
    else:
        message = user + ' exited'
        if not users.setdefault(user, False):
            message += ' (ANOMALY)'
        users[user] = False
    print(message)