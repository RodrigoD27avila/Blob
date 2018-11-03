function foo()
    a = 10
    function bar()
        a = a + 1
    end
    print(a)
    bar()
    print(a)
end

foo()

function rec(a)
    print(a)
    rec(a + 1)
end

rec(0)
