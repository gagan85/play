

class Operation:
    def __init__(self, transaction):
        self.transaction = transaction


class Read(Operation):
    def __init__(self, transaction, data):
        self.data = data;
        super(transaction)


class Write(Operation):
    def __init__(self, transaction, data):
        self.data = data
        super(transaction)


class Commit(Operation):
    def __init__(self, transaction):
        super(transaction)


class Transaction:
    
