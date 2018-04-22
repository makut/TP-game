Homework strategy game

В игре представлены две воинствующие расы: люди и орки. Каждый персонаж может быть воином, лучником или доктором.

В начале игры каждый из игроков (один играет за людей, другой -- за орков). Для создания персонажей для каждого игрока создается абстрактная фабрика для его выбранной фрации. Сама фабрика формируется по объекту орка или человека (без знания о роли персонажа), чтобы задать общие характеристики (например, внешность) всех персонажей конструируемой армии. В методы получения готового персонажа в фабрику передается абстрактный персонаж (воин, луник или доктор) из тех же соображений. Сами по себе эти абстрактные экземпляры в обоих случаях собираются с помощью Builder'а. Его смысл заключается в избежании громоздких кострукторо при создании.

Архитектура армии представлена в виде Компоновщика, который содержит на верхнем уровне Армию, которая может состоять из нескольких батальонов, каждый из которых состоит из нескольких рот, а те, в свою очередь, состоят из отдельных солдат. Битва происходит автоматически путем вызова метода executeBattle у класса Battle, который говорит, кто побеждает в этой схватке. С помощью декораторов настраиваются награда победившей команде и санкции по отношению к проигравшей.
