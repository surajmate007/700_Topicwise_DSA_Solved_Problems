// the link for above question is :       https://www.baeldung.com/java-string-immutable

// An immutable object is an object whose internal state remains constant after it has been entirely created.
// This means that once the object has been assigned to a variable, we can neither update the reference nor mutate the internal state by any means.
// The key benefits of keeping this class as immutable are caching, security, synchronization, and performance.
  
// The String is the most widely used data structure. Caching the String literals and reusing them saves a lot of heap space because different
// String variables refer to the same object in the String pool. String intern pool serves exactly this purpose.
// Java String Pool is the special memory region where Strings are stored by the JVM. Since Strings are immutable in Java, the JVM optimizes
// the amount of memory allocated for them by storing only one copy of each literal String in the pool. This process is called interning:
