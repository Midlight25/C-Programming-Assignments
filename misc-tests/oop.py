# Object Oriented Programing Training


class Employee:

    """
    Employee Class:
    Initalizes an Employee Instance using name and pay as parameters.
    Automatically computes fullname and email from arguments.

    """

    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first + "." + last + "@lastwhisper.com"

    def fullname(self):
        return '{} {}'.format(self.first, self.last)


emp_1 = Employee('Correy', 'Schaffer', 50000)
emp_2 = Employee('Whitley', 'Schnee', 100000)

print(emp_1.fullname())
print(emp_2.fullname())

print(emp_1.email)

print(Employee.fullname(emp_1))
