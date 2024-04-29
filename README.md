# WarriorAIProject

## Blueprints

### 1. `BP_Player`

Blueprint Игрока, наследуется от [`AWarriorAIProjectCharacter`](#6-awarrioraiprojectcharacter)

Управление:

- На **`ЛКМ`** - Атака

- На **`H`** - Использовать зелье

- На **`F`** - Произвести звук

### 2. `BP_Warrior`

Blueprint Бойца, наследуется от [`AWarriorCharacter`](#7-awarriorcharacter)

### 3. `AIC_BP_EnemyBase`

Blueprint AIController Бойца, наследуется от [`AAICEnemyBase`](#8-aaicenemybase)



## C++ Классы и настраиваемые свойства

### 1. `UHealthComponent`

Компонент здоровья персонажа

- `float currentHealth` - Текущее здоровье (оно же стартовое)
- `float maxHealth` - Максимальное здоровье
- `OnDeath` - Делегат, вызываемый при смерти

### 2. `ACompWithPriority`

Базовый класс компонента имеющего приоритет

- `int priority` - Приоритет действия
- `int GetPriority()` - Виртуальный определенный метод, BlueprintCallable
- `void SetPriority(int newPriority)` - Виртуальный определенный метод, BlueprintCallable

### 3. `UAttackComponent`

Компонент атаки, наследуемый от [`ACompWithPriority`](#2-acompwithpriority)

- `OnAttack` - Делегат, вызываемый при начале атаки
- `OnAttackFinished` - Делегат, вызываемый при завершении атаки

### 4. `UWeaponComponent`

Компонент оружия

- `OnEquip` - Делегат, вызываемый при экипирования оружия
- `OnEquipFinished` - Делегат, вызываемый при завершении экипирования оружия
- `OnUnequip` - Делегат, вызываемый при снятия оружия
- `OnUnequipFinished` - Делегат, вызываемый при снятия экипирования оружия

### 5. `UHealPotionsComponent`

Компонент управления эликсирами здоровья, наследуемый от [`ACompWithPriority`](#2-acompwithpriority)

- `int potionsAmount` - Количество эликсиров (оно же стартовое)
- `float potionsHealPower` - Сила исцеления зелий
- `OnUsePotionStart` - Делегат, вызываемый при начале использования эликсира здоровья
- `OnUsePotionEnd` - Делегат, вызываемый при завершении использования эликсира здоровья
- `int AddPotions(int addPotionsAmount)` - BlueprintCallable метод, добавляющий эликсиры и возвращающий их новое число

### 6. `AWarriorAIProjectCharacter`

Класс персонажа Игрока

- [`HealthComponent`](#1-uhealthcomponent) - Компонент здоровья
- [`AttackComponent`](#3-uattackcomponent) - Компонент атаки
- [`HealPotionsComponent`](#5-uhealpotionscomponent) - Компонент управления эликсирами здоровья

### 7. `AWarriorCharacter`

Класс Бойца

- [`HealthComponent`](#1-uhealthcomponent) - Компонент здоровья
- [`AttackComponent`](#3-uattackcomponent) - Компонент атаки
- [`WeaponComponent`](#4-uweaponcomponent) - Компонент оружия
- [`HealPotionsComponent`](#5-uhealpotionscomponent) - Компонент управления эликсирами здоровья

### 8. `AAICEnemyBase`

Класс AI контроллера базового врага

- `AIPerceptionComponent` - Компонент восприятия AI, по умолчанию имеет три конфига (Sight, Hearing, Damage)
