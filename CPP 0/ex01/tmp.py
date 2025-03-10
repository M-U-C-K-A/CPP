import pyautogui
import time

contact_list = [("John", "Doe", "Johnny", "123-456-7890", "Loves pizza"),
				("Jane", "Smith", "Janie", "987-654-3210", "Scared of spiders"),
				("Michael", "Johnson", "Mick", "555-123-4567", "Loves music"),
				("Alice", "Johnson", "Ally", "555-123-4567", "Plays the violin"),
				("Bob", "Brown", "Bobby", "555-765-4321", "Afraid of heights"),
				("Charlie", "Davis", "Chuck", "555-567-1234", "Dreams of space travel"),
				("David", "Evans", "Dave", "555-890-1234", "Loves books"),
				("Eva", "Frank", "Evy", "555-111-5678", "Wants to travel"),
				("Fred", "Garcia", "Freddie", "246-902-1189", "Dreams of having a dog"),
				("Gabriel", "Hall", "Gabe", "549-273-6281", "Loves video games"),
				("Hannah", "Ivanov", "Hana", "854-391-7592", "Loves cats"),
				("Isabella", "Jenkins", "Izzy", "639-852-4671", "Dreams of being a pop star"),
				("Julian", "Khan", "Juju", "473-219-8536", "Loves sports"),
				("Kate", "Larson", "Katie", "627-945-3821", "Dreams of being a scientist"),
				("Lucas", "Martin", "Luc", "935-467-2198", "Dreams of being a superhero")]

print("\033[2J\033[1;1H\033[1m\033[31m🚨 FOCUS ./PHONEBOOK 🚨\033[0m")

for i in range(25):
	time.sleep(0.1)
	print("\033[0m\033[33m  " + str(i*4) + "%", end="\r")

for contact in contact_list:
	print("\n\033[0m\033[32mAdding contact: ")
	pyautogui.typewrite("ADD")
	pyautogui.press('enter')
	pyautogui.typewrite(contact[0])
	pyautogui.press('enter')
	pyautogui.typewrite(contact[1])
	pyautogui.press('enter')
	print("🧑 \033[1m\033[37m " + contact[0] + " " + contact[1] + "\033[0m (" + contact[2] + ")")
	pyautogui.typewrite(contact[2])
	pyautogui.press('enter')
	pyautogui.typewrite(contact[3])
	print("👂  phone number : \033[1m" + contact[3])
	pyautogui.press('enter')
	pyautogui.typewrite(contact[4])
	pyautogui.press('enter')
	print("\033[0m🔑  darkest secret : \033[2m\033[3m" + contact[4])

